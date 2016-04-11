/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pretraga;

import java.util.List;

/**
 *
 * @author aleksandarx
 */
public class Pretraga {

    /**
     * @param args the command line arguments
     */
    
    
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        Search s = new Search("/Users/aleksandarx/NetBeansProjects/Pretraga/src/Documents/");
        
        String input = "computers";
        
        
        s.test(input);
        
        List<String> test = s.searchByCategory("computers", Search.CONTENT, false);
        System.out.println("Hits: " + test.size());
        for(int i = 0; i < test.size(); i++)
            System.out.println(i + ". " + test.get(i));
        
        //s.searchBool(10, 27);
        
        
    }
    
}
