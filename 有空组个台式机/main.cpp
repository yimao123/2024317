//一，构造原则1：
//如果子类没有定义构造方法，则调用父类的无参数的构造方法。
//#include <iostream>
//using namespace std;
//class ar
//{
//public:				//不写public会报无法访问private的错误
//	ar() 			//父类有无参数构造方法
//	{
//		cout << "来了支自动步枪" << endl;
//	}
//};
//class scar :public ar
//{				    //子类没有定义构造方法
//};
//int main()
//{
//	ar Alice;
//	scar Bob();
//	system("pause");
//}
//可见父类的无参数构造函数在创建子类时被调用了。
//需要注意的是，如果在实例后加了圆括号：
//
//ar Alice();
//scar Bob();
//1
//2
//则运行结果为空，但是也不报错
//二，构造原则2：
//在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。
//#include <iostream>
//using namespace std;
//class ar
//{
//public:
//	ar()						//父类有无参数构造方法
//	{
//		cout << "来了支自动步枪" << endl;
//	}
//};
//class scar :public ar
//{
//public:
//	scar()					   //子类有无参数构造方法
//	{
//		cout << "来了把Scar" << endl;
//	}
//};
//int main()
//{
//	ar Alice;
//	scar Bob;
//	system("pause");
//	//可见，虽然子类定义了构造函数，但是在创建子类时，仍然会调用父类的构造函数。
//}
//三，构造原则3：
//在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
//#include <iostream>
//using namespace std;
//class ar
//{
//public:
//	ar(int dmg)				//父类有带参数的构造方法
//	{
//		cout << "来了支自动步枪,单发伤害为" << dmg << endl;
//	}
//};
//class scar :public ar
//{
//public:
//	scar(int dmg) :ar(dmg)				//子类构造方法带了参数，且显式调用父类的构造方法
//	{
//		cout << "来了把Scar,单发伤害是" << dmg << endl;
//	}
//};
//int main()
//{
//	ar Alice(45);
//	scar Bob(22);
//	system("pause");
//	//到这儿基本明白了，无论子类的构造函数是啥样，创建子类必定调用父类的构造函数。所以父类的构造函数需要参数，子类却没法给，就得报错了。
//}
//四，构造原则4：
//如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式。

//#include <iostream>
//using namespace std;
//class ar
//{
//public:
//	ar(int dmg)							//父类有带参数的构造方法
//	{
//		cout << "来了支自动步枪,单发伤害为" << dmg << endl;
//	}
//};
//class scar :public ar
//{
//public:
//	scar(int dmg) :ar(dmg)				//子类构造方法带参数，且显式调用父类的构造方法
//	{
//		cout << "来了把Scar,单发伤害是" << dmg << endl;
//		ar(61);							//子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式，且只能在这里调用
//	}
//};
//int main()
//{
//	ar Alice(45);
//	scar Bob(42);
//	system("pause");
//	//五，反转来了
//	//	上面几个例子看下来，似乎有了这么个表：
//
//	//	父类构造函数的参数数量	子类构造函数的参数数量要求
//	//	无	没要求
//	//	N(N>0)	≥N且包含父类的所有构造函数参数
//
//}
#include <iostream>
using namespace std;
class ar
{
public:
	ar(int dmg, int bullet)					    //父类有带2个参数的构造方法
	{
		cout << "来了支自动步枪,单发伤害为" << dmg;
		cout << "，一个弹匣有" << bullet << "发子弹" << endl;
	}
};
class scar :public ar
{
public:
	scar(int dmg);							    //声明子类的构造方法，它只带1个参数，可以吗？
};
scar::scar(int dmg) :ar(dmg, 30)				//定义子类构造方法，调用父类的构造方法时把另一个参数赋值
{
	cout << "来了把Scar,单发伤害是" << dmg << endl;
}
int main()
{
	ar Alice(61, 20);
	scar Bob(42);
	system("pause");
}