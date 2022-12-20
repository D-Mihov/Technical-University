import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class WorkerThread implements Runnable
{
    private String message;
    public WorkerThread(String a)
    {
        this.message=a;
    }
    public void run()
    {
        System.out.println(Thread.currentThread().getName()+" (Start) message = "+message);
        processmessage();
        System.out.println(Thread.currentThread().getName()+" (End)");
    }
    private void processmessage()
    {
        try
        {
            Thread.sleep(5000);
        }
        catch (InterruptedException e)
        {
            System.out.println(e);
        }
    }


    public static void main(String[] args)
    {
        ExecutorService executor = Executors.newFixedThreadPool(5);
        for (int i = 0; i < 10; i++)
        {
            Runnable obj = new WorkerThread("" + i);
            executor.execute(obj);
        }
        executor.shutdown();
        while (!executor.isTerminated())
        {
        }
        System.out.println("********All threads are Finished********");
    }


}
