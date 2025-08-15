import java.util.concurrent.CountDownLatch;

class Foo {

    private CountDownLatch latch1;
    private CountDownLatch latch2;

    public Foo() {
        latch1 = new CountDownLatch(1); // Signals that first() is done
        latch2 = new CountDownLatch(1); // Signals that second() is done
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        latch1.countDown(); // Allow second() to proceed
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latch1.await(); // Wait until first() finishes
        printSecond.run();
        latch2.countDown(); // Allow third() to proceed
    }

    public void third(Runnable printThird) throws InterruptedException {
        latch2.await(); // Wait until second() finishes
        printThird.run();
    }
}
