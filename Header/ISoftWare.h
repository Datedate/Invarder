#pragma once
class ISoftWare
{
public:
	virtual ~ISoftWare()=0;
	virtual void Init()=0;
	virtual void Run() = 0;
};
