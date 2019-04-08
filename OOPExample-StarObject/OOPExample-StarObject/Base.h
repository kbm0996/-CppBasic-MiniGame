#ifndef __BASE_H__
#define __BASE_H__

#define df_LINE 20

class BaseObject
{
protected:
	int _X = 0;

public:
	virtual bool Action() = 0;	// 순수 가상 함수 / interface class = Java의 interface 역할
	virtual void Draw() = 0;
};

extern BaseObject * g_pArray[df_LINE];

#endif
