package xyz.hzh.pg;

import java.io.IOException;

import xyz.hzh.pg.pattern.behavioral.ObserverPattern;

/**
 * Hello world!
 *
 */
public class App {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        System.out.println();

        ObserverPattern.demo();
        try {
            System.in.read();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
