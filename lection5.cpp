
//================================================================================================================//
/*                                      касты в c++

В Си каст был вида (тип)(значение), например (int)3.5
в с++ касты из Си продолжают работать, вместе с этим появились новые касты:
const_cast       <тип>(значение) - каст, позволяющий надеть и снять модификаторы const, (???)
static_cast - каст с сохранением значения
reinterpret_cast - каст, сохраняющий битовое представление
dynamic_cast - новый каст без аналогов в си, который учитывает тип объекта, вернет null если каст невозможен, очень
тяжелая операция

в иерархии классов не следуюет использовать каст из си
*/
//================================================================================================================//
/*
									  Шаблоны

без шаблонов код выглядит как-то так:
int mymax(int  int)
float mymax(float float)
double mymax(double double)
{
	return a > b? a : b;
}

с шаблонами:

template<typename T> T mymax(T a, T b)
{
	 return a > b? a : b;
}
описание шаблона похоже на описание структуры и ничего не задает
компилятор создает фукнцию по шаблону только в момент ее использования
int a,b,c;
c = mymax(a,b);<-в этот момент
uint a;
int b,c;
c = mymax<int>(b,c);<-можно явно указать тип шаблона, тогда компилятор явно вызывает функцию с 19 строки,
					  тогда произойдет автоматическая конверсия типов

шаблоны также бывают для классов

template<typename T> class A{
	T *v;
public:
	A(T *x): v(x){}
	A(): v(nullptr){}
	void set(T *x){v = x;}
}
A<int> a;
int x;
a.set(&x);

*/
//================================================================================================================//
/*
											namespace

namespace ABC{

	int f();<-имя объектов внутри неймспейса искажается, на деле имя его будет другим

}
неймспейсы необходимы для того, чтобы одинаковые имена функций и переменных не конфликтовали между собой

int main(){

	int x = ABC::f();

}

важный частный случай неймспейсов-std
чтобы не писать постоянно ::std, можно прописать using namespace std;(считается плохим тоном хаххахх)
также существуют анонимные неймспейсы

//================================================================================================================//

*/
#include <string.h>
struct A
{
	static int x;						  // бывают статические поля
	static int myconst() { return 5; }	  // статические методы не имеют доступа к полям класса
};
int c = A::myconst();	 // можно вызвать без экземпляра объекта
//================================================================================================================//
/*
 */
int x;
int &y = x;
int f(int &x)
{
	return x;
}
int a, b;
// a = f(b);

struct Str
{
	const char *p;
	Str() : p(0) {}
	Str(const char *x)
	{
		size_t len = strlen(x);
		p = (char *)malloc(len + 1);
		strcpy(p, x);
	}

	// rvalue ссылки
	// перемещающий оператор присваивания
	a = std::move(b);	 // std::move создает rvalue reference
};
