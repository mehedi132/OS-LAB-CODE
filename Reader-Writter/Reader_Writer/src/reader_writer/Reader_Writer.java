/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reader_writer;

import static java.lang.System.out;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.Semaphore;
import static jdk.nashorn.internal.objects.ArrayBufferView.buffer;

/**
 *
 * @author mh200
 */
public class Reader_Writer {
   
    
   Queue<Integer> buffer = new LinkedList<Integer>();
    static Semaphore readLock = new Semaphore(1);
    static Semaphore writeLock = new Semaphore(1);
    static int readCount = 0;
    int i=0;
    
  
    
    
  class Read implements Runnable {
        @Override
        public void run() {
            try {
                
                 
                 
                
                    
               
                //Acquire Section
                readLock.acquire();
                readCount++;
                if(i==0)
                {
                     buffer.add(1);
             buffer.add(2);
               buffer.add(3);
                 buffer.add(4);
                }
                i++;
                System.out.println("Data in Bufer " 
                          + buffer);
                
                
                 int consumed_item = buffer.remove();
                if (readCount == 1) {
                    writeLock.acquire();
                }
                readLock.release();

                //Reading section
                System.out.println("Thread "+Thread.currentThread().getName() + " : Reading Data " + consumed_item + " from the buffer");
                Thread.sleep(1500);
                System.out.println("Thread "+Thread.currentThread().getName() + " has FINISHED READING");
System.out.println("Data in Bufer " 
                          + buffer);
                //Releasing section
                readLock.acquire();
                readCount--;
                if(readCount == 0) {
                    writeLock.release();
                }
                readLock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
     
  class Write implements Runnable {
        @Override
        public void run() {
            try {
                writeLock.acquire();
                buffer.add(10);
                
                System.out.println("Thread "+Thread.currentThread().getName() + " is WRITING 10");
                Thread.sleep(2500);
                System.out.println("Thread "+Thread.currentThread().getName() + " has finished WRITING");
                System.out.println("Data in Bufer " 
                          + buffer);
                writeLock.release();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
    }
 
      public static void main(String[] args) throws Exception {
         
           

           
                          
          Reader_Writer rc= new Reader_Writer();
          
          
        Read read = rc.new Read();
        Write write = rc.new Write();
        Thread t1 = new Thread(read);
        t1.setName("Reader 1");
        Thread t2 = new Thread(read);
        t2.setName("Reader 2");
        Thread t3 = new Thread(write);
        t3.setName("Writter 1");
        Thread t4 = new Thread(write);
        t4.setName("Writter 2");
        t1.start();
        t2.start();
        t3.start();
        t4.start();
    }
    
    
    
   
    
}
