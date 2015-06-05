/*
题目：设计一个类，我们只能生成该类的一个实例
扩展：大话设计模式，
注意：自己在纸上书写程序@Qzl

*/
//单线程
class Singleton {
	private Singleton instance;
	private Singleton(){ } //静态构造函数
	public Singleton getInstance(){
		if(instance == null)
			instance = new Singleton();
		return instance;
	}
}
//多线程
class Singleton1 {
	private Singleton1 instance;
	private static readonly object sync = new object();
	private Singleton(){ }
	public Singleton1 getInstance(){
		if(instance == null){ //提高效率，没必要每次试图得到实例时都加入同步锁
			lock(sync){ //加同步锁
				if(instance == null)
					instance = new Singleton1();
			}
		}
		return instance;
	}
}
//C#静态初始化方法
class sealed class Singleton2{
	private static readonly Singleton2 instance = new Singleton2();
	private Singleton2(){}
	public Singleton2 getInstance(){
		return instance;
	}
}
