package xyz.hzh.pg.pattern.behavioral;

import java.util.ArrayList;
import java.util.List;

/**
 * 被观察目标接口定义
 */
interface IObserver {
    public abstract void update(Object msg);
}

/**
 * 观察者接口定义
 */
interface ISubject {
    abstract void attach(IObserver observer);

    abstract void detach(IObserver observer);

    abstract void doNotify();

}

/**
 * 观察者对象简单实现
 */
class SubjectImpl implements ISubject {
    private List<IObserver> mObserverList;

    public SubjectImpl() {
        mObserverList = new ArrayList<IObserver>();
    }

    @Override
    public void attach(IObserver observer) {
        this.mObserverList.add(observer);
    }

    @Override
    public void detach(IObserver observer) {
        this.mObserverList.remove(observer);
    }

    @Override
    public void doNotify() {
        howManyRegisterObserver();
        for (IObserver observer : this.mObserverList) {
            observer.update("");
        }
    }

    private void howManyRegisterObserver() {
        System.out.println("Register " + this.mObserverList.size() + " observers");
    }
}

/**
 * ObserverImpl 类是 IObserver 接口的实现，用于接收并打印解码后的消息。
 */
class ObserverImpl implements IObserver {
    public ObserverImpl() {
    }

    @Override
    public void update(Object msg) {
        String decodeMsg = (String) msg;
        System.out.println("ObserverImpl receive message" + decodeMsg);
    }
}


/**
 * The ObserverAnotherImpl class is an implementation of the IObserver interface that receives and
 * prints a decoded message.
 */
class ObserverAnotherImpl implements IObserver {
    public ObserverAnotherImpl() {
    }

    @Override
    public void update(Object msg) {
        String decodeMsg = (String) msg;
        System.out.println("ObserverAnotherImpl receive message" + decodeMsg);
    }
}

/**
 * The ObserverPattern class demonstrates the implementation of the Observer design pattern in Java.
 */
public class ObserverPattern {
    public static void demo() {
        /// 模拟客户类简单实现
        ISubject subject = new SubjectImpl();
        IObserver observeFirst = new ObserverImpl();
        subject.attach(observeFirst);

        subject.doNotify();
        IObserver observerSecond = new ObserverAnotherImpl();
        subject.attach(observerSecond);
        subject.doNotify();
    }
}
