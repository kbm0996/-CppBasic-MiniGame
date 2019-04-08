#ifndef __BASE_H__
#define __BASE_H__

#define df_LINE 20

class BaseObject
{
protected:
	int _X = 0;

public:
	virtual bool Action() = 0;	// ���� ���� �Լ� / interface class = Java�� interface ����
	virtual void Draw() = 0;
};

extern BaseObject * g_pArray[df_LINE];

#endif
