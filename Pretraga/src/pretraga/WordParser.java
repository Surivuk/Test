/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pretraga;

import java.io.File;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author aleksandarx
 */
public class WordParser {
    
    private String filePath;
    private HashMap<String, Integer> hashMap;
    private boolean parserSuccessful;
    
    public WordParser(String filePath){
        this.filePath = filePath;
        this.hashMap = new HashMap<>();
        parserSuccessful = false;
        pars();
    }
    
    private void pars(){
        try{
            Scanner scan = new Scanner(new File(filePath));
            while (scan.hasNext()) {                
                String tmp = proccessWord(scan.next());
                if(hashMap.containsKey(tmp)){
                    Integer tmpCount = hashMap.get(tmp);
                    hashMap.replace(tmp, tmpCount + 1);
                }
                else
                    hashMap.put(tmp, 1);
            }
            parserSuccessful = true;
        }
        catch(Exception e){
            System.err.println(e.toString());
        }
    }
    
    public int gerFrequency(String word){
        if(parserSuccessful){
            if(hashMap.containsKey(word))
                return hashMap.get(word);
        }
        return 0; 
    }
    
    private String proccessWord(String word){
        if(word.endsWith("..."))
            return word.substring(0, word.length() - 3);
        if(word.endsWith(",") || word.endsWith(".") || word.endsWith("!") || word.endsWith("?") 
        || word.endsWith(")") || word.endsWith("]") || word.endsWith("}") || word.endsWith(":"))
            return word.substring(0, word.length() - 1);
        return word;
    }
}
