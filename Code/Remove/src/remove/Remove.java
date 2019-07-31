/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package remove;

/**
 *
 * @author allen
 */
public class Remove {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int input = -1;
        try {
            input = System.in.read();
        } catch (Exception e) {

        }
        String in = "";
        while (input != 10) {
            in += (char) input;
            try {
                input = System.in.read();
            } catch (Exception e) {

            }
        }
        String rep = "(?i)j";
        rep += "ava";
        System.out.println(in.replaceAll(rep, ""));
    }

}
