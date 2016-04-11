/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pretraga;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.index.Term;

import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.TermQuery;
import org.apache.lucene.search.TopScoreDocCollector;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.store.Directory;
import org.apache.lucene.queryparser.classic.QueryParser;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import org.apache.lucene.analysis.TokenFilter;
import org.apache.lucene.codecs.blocktree.FieldReader;
import org.apache.lucene.document.FieldType;
import org.apache.lucene.document.IntField;
import org.apache.lucene.document.LongField;
import org.apache.lucene.index.FilterLeafReader.FilterTerms;
import org.apache.lucene.index.MultiTerms;
import org.apache.lucene.index.Terms;
import org.apache.lucene.queries.BooleanFilter;
import org.apache.lucene.queryparser.classic.ParseException;
import static org.apache.lucene.queryparser.classic.QueryParserConstants.Range;
import org.apache.lucene.search.BooleanQuery;
import org.apache.lucene.search.NumericRangeQuery;
import org.apache.lucene.search.TermRangeQuery;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.search.similarities.ClassicSimilarity;
import org.apache.lucene.search.similarities.DefaultSimilarity;
import org.apache.lucene.search.similarities.Similarity;
import org.apache.lucene.search.similarities.TFIDFSimilarity;
import org.apache.lucene.util.BytesRef;
import org.apache.lucene.index.TermsEnum;
import org.apache.lucene.search.BooleanQuery.Builder;

/**
 *
 * @author aleksandarx
 */

import org.apache.commons.math3.linear.OpenMapRealVector;
import org.apache.commons.math3.linear.RealVectorFormat;
import org.apache.commons.math3.linear.SparseRealVector;

import org.apache.lucene.index.Fields;
import org.apache.lucene.index.LeafReaderContext;
import org.apache.lucene.search.BooleanClause;
import org.apache.lucene.search.CollectionStatistics;
import org.apache.lucene.search.TermStatistics;

import org.junit.Assert;


class IsolationSimilarity extends ClassicSimilarity {
    public IsolationSimilarity(){
    }
    public float idf(int docFreq, int numDocs) {
        return(float)1.0;
    }
    public float coord(int overlap, int maxOverlap) {
        return 1.0f;
    }
    public float lengthNorm(String fieldName, int numTerms) {
        return 1.0f;
    }
}



public class Search {

    private final String indexDirectoryPath;
    private final Analyzer analyzer;
    private final String docDirectoryPath;
    
    public static String CONTENT = "content";
    public static String TITLE = "title";
    public static String SIZE = "size";
    
    public Search(String docDir) {
        indexDirectoryPath = "/Users/aleksandarx/NetBeansProjects/Pretraga/src/Index/";
        docDirectoryPath = docDir;
        analyzer = new StandardAnalyzer();
        loadAllDocs(docDir);
    }
     
    public List<String> searchBool(long lowLine, long hightLine){
        try{
            Directory dir = FSDirectory.open(new File(indexDirectoryPath).toPath());

            IndexReader reader = DirectoryReader.open(dir);
            IndexSearcher searcher = new IndexSearcher(reader);
            
            
            Query q = NumericRangeQuery.newLongRange(SIZE, lowLine, hightLine, true, true);
            
            
            
            
            TopScoreDocCollector collector = TopScoreDocCollector.create(10);
            searcher.search(q, collector);
            List<String> retList = new ArrayList<>();
            TopDocs docs = collector.topDocs();
            System.out.println("Hits: " + docs.totalHits);
            for(int i = 0; i < docs.scoreDocs.length; i++){
                Document d = reader.document(docs.scoreDocs[i].doc);
                System.out.println(d.get(TITLE) + ", " + d.get(SIZE));
            }
            
            
            reader.close();
            dir.close();
            return retList;
        }
        catch(Exception e){
            System.err.println(e.toString());
            return null;
        }
    }
    
    public void addDocument(String indexName, String documentPath){
        try{
            Directory dir = FSDirectory.open(new File(indexDirectoryPath).toPath());
            IndexWriterConfig config = new IndexWriterConfig(this.analyzer);
            config.setSimilarity(new ClassicSimilarity());
            IndexWriter writer = new IndexWriter(dir, config);
            Document doc = new Document();
            File file = new File(documentPath);
            String fileSize = String.valueOf(file.length());
            String content = new String(Files.readAllBytes(file.toPath()),StandardCharsets.UTF_8);
            BytesRef by = new BytesRef(fileSize.getBytes());
            
            FieldType textType = new FieldType(TextField.TYPE_STORED);
            textType.setStored(true);
            textType.setStoreTermVectors(true);
            textType.setStoreTermVectorOffsets(true);
            
            doc.add(new LongField(SIZE, file.length(), Field.Store.YES));
            doc.add(new Field(TITLE, indexName, textType));
            doc.add(new Field(CONTENT, content, textType));
            writer.addDocument(doc);
            writer.close();
            dir.close();
        }
        catch(Exception e)
        {
           System.err.println(e.toString());
        }
    }
        
    public List<String> searchByCategory(String searchingTerm, String category, boolean veryPrecision){
        try{
            Directory dir = FSDirectory.open(new File(indexDirectoryPath).toPath());

            IndexReader reader = DirectoryReader.open(dir);
            IndexSearcher searcher = new IndexSearcher(reader);
            searcher.setSimilarity(new ClassicSimilarity());
            
            QueryParser parser = new QueryParser(category, analyzer);
            String queryText = searchingTerm.toLowerCase();
            if(!veryPrecision)
                queryText += "*";
            Query q = parser.parse(queryText);

            TopScoreDocCollector collector = TopScoreDocCollector.create(10);
            searcher.search(q, collector);
            TopDocs docs = collector.topDocs();
            List<String> ret = new ArrayList<>();
            for(int i = 0; i < docs.totalHits; i++){
                Document d = reader.document(docs.scoreDocs[i].doc);
                ret.add(d.get(category)+ ", " + d.get(SIZE) + ", score: " + docs.scoreDocs[i].score);
            }
            reader.close();
            dir.close();
            return ret;
        }
        catch(Exception e){
           System.err.println(e.toString()); 
           return new ArrayList<>();
        }
    }
    
    private void loadAllDocs(String docDir){
        File folder = new File(docDir);
        ArrayList<String> list = new ArrayList<>();
        for (final File fileEntry : folder.listFiles()) {
            if (!fileEntry.isDirectory()) {
                if(fileEntry.getName().endsWith(".txt"))
                    list.add(fileEntry.getName());
            }
        }
        for(int i = 0; i < list.size(); i++){
            String fileName = list.get(i).split(".txt")[0];
            if(searchByCategory(fileName, TITLE, true).isEmpty())
                addDocument(fileName, docDir + list.get(i));
        }
    }
    
    public void test(String vec){
        List<String> vector = processInput(vec);
        HashMap<String, Long> map = new HashMap<>();
        try{
            Directory dir = FSDirectory.open(new File(indexDirectoryPath).toPath());

            IndexReader reader = DirectoryReader.open(dir);
            IndexSearcher searcher = new IndexSearcher(reader);

            List<Integer> docId = getDocumentsFromVector(vector, reader, searcher);
            
            for(int i = 0; i < docId.size(); i++){
                Fields ff = reader.getTermVectors(docId.get(i));
                Terms terms = ff.terms(CONTENT);
                
                TermsEnum te = terms.iterator();
                Object tmp = te.next();
                while (tmp != null) {
                    BytesRef by = (BytesRef) tmp;
                    String term = by.utf8ToString();

                    ClassicSimilarity sim = null;
                    if (searcher.getSimilarity(true) instanceof ClassicSimilarity) {
                        sim = (ClassicSimilarity) searcher.getSimilarity(true);
                    }
                    float idf = sim.idf(te.docFreq(), reader.maxDoc());
                    float tf = sim.tf(te.totalTermFreq());
                    //System.out.println("idf = " + idf + ", tf = " + tf + ", docF: " + te.totalTermFreq());
                    TermStatistics ts = new TermStatistics(by, te.docFreq(), te.totalTermFreq());
                    CollectionStatistics s = new CollectionStatistics(CONTENT, reader.maxDoc(), terms.getDocCount(), terms.getSumTotalTermFreq(), terms.getSumDocFreq());
                    Document d = reader.document(docId.get(i));
                    if(vector.contains(term)){
                        float ttt = sim.simScorer(sim.computeWeight(s, ts), reader.getContext().leaves().get(0)).score(docId.get(i), te.totalTermFreq());
                        System.out.println(ttt + ", " + d.get(TITLE) + ", term: " + term);
                    }
                    tmp = te.next();
                }

                /*Iterator<String> ss = ff.iterator();
                while (ss.hasNext()) {
                    String fieldString = ss.next();
                    System.out.println(fieldString);
                }*/
            }     
        }
        catch(Exception e){
            
        }
    }
    
    private List<String> processInput(String vec){
        List<String> ret = new ArrayList<>();
        String[] tmp = vec.split(" ");
        for(int i = 0; i < tmp.length; i++)
            ret.add(tmp[i].toLowerCase());
        return ret;
    }
    
    private List<Integer> getDocumentsFromVector(List<String> vector, IndexReader reader, IndexSearcher searcher){
        List<Integer> docId = new ArrayList<>() ;
        try{
            Builder builder = new BooleanQuery.Builder();
            for (int i = 0; i < vector.size(); i++) {
                QueryParser parser = new QueryParser(CONTENT, analyzer);
                Query q = parser.parse(vector.get(i).toLowerCase());
                builder.add(q, BooleanClause.Occur.SHOULD);
            }
            Query queryForSearching = builder.build();

            TopScoreDocCollector collector = TopScoreDocCollector.create(10);
            searcher.search(queryForSearching, collector);
            TopDocs docs = collector.topDocs();
            for (int i = 0; i < docs.totalHits; i++) {
                if(!docId.contains(docs.scoreDocs[i].doc))
                    docId.add(docs.scoreDocs[i].doc);
            }
            return docId;
        }
        catch(Exception e){
            System.err.println(e.toString());
            return docId;
        }
    }
    
}
    
