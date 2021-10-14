/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package producerconsumer;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 *
 */
public class producerconsumer {

     Scanner sc = new Scanner(System.in);     
        int bufferSize = sc.nextInt();   
    private final Queue<Integer> buffer = new LinkedList<>();
    
    Semaphore mutex = new Semaphore(1);   
    Semaphore full = new Semaphore(0);
    Semaphore empty = new Semaphore(bufferSize);
    

    void ProduceProcess() {
        while (true) {
            try {                
                empty.acquire();                                
                mutex.acquire();
                 System.out.println(Thread.currentThread().getName() + " : Data  to insert in the buffer");
                 Scanner sc = new Scanner(System.in);
                    System.out.print("Data: ");
                    int produced_item = sc.nextInt();                              
                buffer.add(produced_item);                             
                
                System.out.println("Empty Space : "+ (bufferSize - buffer.size()));
                System.out.println( "Full Space : " + buffer.size());
              
                 mutex.release();                             
                full.release(1);
                              
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(producerconsumer.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
    }

    
    void ConsumeProcess() {

        while (true) {
            try {                
                full.acquire();                            
                mutex.acquire();                            
                int consumed_item = buffer.remove();
                
                System.out.println(Thread.currentThread().getName() + " : Consumed Data " + consumed_item + " from the buffer");
                System.out.println("Full Space : " + buffer.size());
                
                mutex.release();
                empty.release();
                Thread.sleep(500);
            } catch (InterruptedException ex) {
                Logger.getLogger(producerconsumer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

   
    class Producer implements Runnable {

        @Override
        public void run() {
          
            ProduceProcess();
        }
    }

   
    class Consumer implements Runnable {

        @Override
        public void run() {          
            ConsumeProcess();
        }
    }

    public static void main(String[] args) {

        System.out.println("Enter Buffer Size: ");
        producerconsumer pc = new producerconsumer();

        Producer p1 = pc.new Producer();
        Producer p2 = pc.new Producer();

        Consumer c1 = pc.new Consumer();
        Consumer c2 = pc.new Consumer();

       
        Thread t1 = new Thread(p1);
        t1.setName("Producer 1");
        Thread t2 = new Thread(p2);
        t2.setName("Producer 2");
        
        Thread t3 = new Thread(c1);
        t3.setName("Consumer 1");
        Thread t4 = new Thread(c2);
        t4.setName("Consumer 2");
       
        t1.start();
        t2.start();        
        t3.start();
        t4.start();
    }

}
