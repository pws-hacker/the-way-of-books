#pragma once
#include "guide.hpp"


// ����06 ������ʹ�ñ༭���Զ����ɵĺ������͸���ȷ�ܾ�
//  ��ֹ copying
//  һ�����Խ� copy ���캯���� copy assignment ����������Ϊ private 
//    ���㹻��ȫ��Ϊ member ���� �� friend �������ǿ��Ե������ private ����
//    �������� �������壬���ĳ�˲������û����һ�����Ӵ���
//	  �������Ʋ��Ǳ�Ҫ ��������ʵ�ֲ��Һ��ٱ�ʹ�ÿ��Բ�д��������
//  �����������ڵĴ��������������ǿ��ܵ�
//		ֻҪ�� copy ���캯�� �� copy assignment ����������Ϊ private �Ϳ��԰쵽
//		�����������Լ�ʵ�ֵ��࣬������һ��ר��Ϊ����ֹ copying ��������Ƶ� base class

// ��ֹ���󱻿��� ֻ��Ҫ�̳� UnCopyAble ����Ϳ�����
class UnCopyAble
{
protected:
	UnCopyAble() {};			// ���� derived �����������
	~UnCopyAble() {};
private:
	UnCopyAble(const UnCopyAble&) {};			// ����ֹ copying
	UnCopyAble& operator=(const UnCopyAble&) {};
};

// ע������ ��˽�м̳�
class HomeForSale : public UnCopyAble
{

};

// ����07 Ϊ��̬�������� virtual ��������
//   C++ ָ�� �� derived class ������һ�� base class ָ�뱻ɾ�������� base class ��һ�� non-virtual ��������
//		����δ�ж���--ʵ��ִ��ʱͨ���������Ƕ���� derived �ɷ�û�����١� ��� �ֲ����� ����
//	 �κ� class ֻҪ���� virtual ��������ȷ��Ӧ����һ�� virtual ��������

class CBaseClassVirtual
{
public:
	CBaseClassVirtual() {};
	~CBaseClassVirtual() { outLog("CBaseClassVirtual ��������ִ��"); };
};


class CTestClassVirtual : public CBaseClassVirtual
{
public:
	CTestClassVirtual() {};
	~CTestClassVirtual() { outLog("CTestClassVirtual ��������ִ��"); };
};



class Class02
{
public:
	void testClassVirtual();
	void testAutoPtr();
	void testSharedPtr();
	void testGetFunc();




};



// ����08 �����쳣������������



// ����09 �����ڹ�������������е��� virtual ����


// ����10 �� operator= ����һ�� reference to *this
//   ������ֵ 
// int x,y,z;
// x = y = z = 15;
// ��ֵ�����ҽ�϶���
// x = (y = (z = 15));
// Ϊ��ʵ��������ֵ����ֵ���������뷵��һ�� reference ָ������������ʵ��
// ��ֻ�Ǹ�Э�飬string vector complex tr1::shared_ptr ��ͬ����

class CChainAssignment
{
public:
	// ���� reference ָ��ǰ����
	// ���������и�ֵ�������
	CChainAssignment& operator = (const CChainAssignment& rhs)
	{
		return *this;
	}
};

// ����11 �� operator = �д��� �����Ҹ�ֵ��
//	�����Ҹ�ֵ�� �����ڶ��󱻸�ֵ���Լ�ʱ
// class CAssignmentSelf { ... };
// CAssignmentSelf ca;
// ca = ca;
// a[i] = a[j];   ��� i = j ��Ǳ�ڵ����Ҹ�ֵ
// *px = *py;	  ��� px �� py ָ��ͬһ������Ǳ�ڵ����Ҹ�ֵ

// ���Ҹ�ֵ����ȫʵ��
class CAssignmentSelfNotSafe
{
public:
	CAssignmentSelfNotSafe(const CAssignmentSelfNotSafe&) {};
	~CAssignmentSelfNotSafe() {};
};

class CAssignmentSelfNotSafeCase
{
public:
	void swap(CAssignmentSelfNotSafeCase& rhs)  // ���� *this �� rhs ������
	{

	};

	// ���ʵ�� rhs.pTest ָ���� ˽�� pTest ָ�� ָ��ͬһ������ 
	CAssignmentSelfNotSafeCase& operator=(const CAssignmentSelfNotSafeCase& rhs)
	{
		// ������� ��ͳ����   ֤ͬ����
		if (this->pTest == rhs.pTest) return *this;



		delete pTest;									// ֹͣʹ�õ�ǰ pTest ָ��
		// rhs.pTest ������ܻ����һ����ָ��
		// ����Ѿ� ֤ͬ���� ��new �����쳣�Ļ�(��Ϊ�ڴ治�����copy���캯���쳣)
		// ���ն������һ�� �յ�ַ
		pTest = new CAssignmentSelfNotSafe(*rhs.pTest); // ʹ�� rhs �е� pTest �ĸ���
		return *this;
	}

	// 1.����쳣��ȫ��
	//CAssignmentSelfNotSafeCase& operator=(const CAssignmentSelfNotSafeCase& rhs)
	//{
	//	CAssignmentSelfNotSafe* pOrig = pTest; // ��סԭ�ȵ� pTest
	//	pTest = new CAssignmentSelfNotSafe(*rhs.pTest);  // �� pTest ָ�� *rhs.pTest �ĸ���
	//	delete pOrig;							// ɾ��ԭ�ȵ� pOrig
	//	return *this;
	//}

	// 2.ʹ�� copy and swap ����
	//CAssignmentSelfNotSafeCase& operator=(const CAssignmentSelfNotSafeCase& rhs)
	//{
	//	CAssignmentSelfNotSafeCase temp(rhs);
	//	swap(temp);
	//	return *this;
	//}


private:
	CAssignmentSelfNotSafe* pTest;
};

// ����12 ���ƶ���ʱ������ÿһ���ɷ�
//  �������֮�������ϵͳ(OO-systems)�Ὣ������ڲ���װ������ֻ����������������󿽱�(����)���Ǳ��Ǵ��ź������Ƶ� copy ���캯���� copy assingment ������
//  ���ǳ�Ϊ copying ����
//    ���Լ���дһ�� copying ������ȷ����1.�������� local ��Ա���� 2.�������� base classes �ڵ��ʵ��� copying ����
// 
// copying ����Ӧ��ȷ�����ơ������ڵ����г�Ա�������������� base class �ɷ֡�
// ��Ҫ������ĳ�� copying ����ʵ����һ�� copying ������Ӧ�ý���ͬ���ܷŽ������������У��������� copying ������ͬ����

class CCopyingFuncBase
{
public:
	CCopyingFuncBase(const CCopyingFuncBase& rhs)
		: m_sName(rhs.m_sName)
	{
		outLog("CCopyingFuncBase copy constructor");
	};
	// �Լ�ʵ�� operator= ��������ÿһ��������Ա������ʱ��Ҫ���и�ֵ
	// ����ⲿ��̳�����࣬�ڳ�ʼ����ʱ��ҲҪ�����ڲ���ĸ�ֵ����
	CCopyingFuncBase& operator=(const CCopyingFuncBase& rhs)
	{
		outLog("CCopyingFuncBase copy assignment operator");
		m_sName = rhs.m_sName;			// ���� rhs ������
		return *this;
	};
private:
	std::string m_sName;
	int m_iAge;							// ҲҪ���п���
};

class CCopyingFuncDerived : public CCopyingFuncBase
{
public:
	CCopyingFuncDerived(const CCopyingFuncDerived& rhs)
		: CCopyingFuncBase(rhs)
		, priority(rhs.priority)
	{
		outLog("CCopyingFuncDerived copy constructor");
	};

	CCopyingFuncDerived& operator=(const CCopyingFuncDerived& rhs)
	{
		outLog("CCopyingFuncDerived copy assignment operator");
		CCopyingFuncBase::operator=(rhs);		// �� base class �ɷֽ��и�ֵ����
		priority = rhs.priority;
		return *this;
	}

private:
	int priority;
};


// ����13 �Զ��������Դ
//  auto_ptr �� ����ָ����� ����ָ��
//		�����Դ�����̷Ž����������
//		�������������������ȷ����Դ���ͷ�
//	���� auto_ptr ������ʱ���Զ�ɾ������ָ֮�����һ��ע����ö�� atuo_ptr ͬʱָ��ͬһ����
//  ����(��Ҫ)����ͨ�� copy ���캯���� copy assigment �������������ǣ����ǻ��� null , ���������õ�ָ�뽫ȡ����Դ��Ψһӵ��Ȩ
class IAutoPtrTest
{

};
class CAutoPtrTest : public IAutoPtrTest
{
public:
	CAutoPtrTest(const std::string& name)
		: m_sName(name)
	{

	}
	std::string m_sName;
};

// ���ü����� �ǻ�ָ��(RCSP)
//	�� RCSP Ҳ������ָ�룬����׷�ٹ��ж��ٶ���ָ��ĳ����Դ����������ָ����ʱ�Զ�ɾ������Դ
//  ʵ�� tr1::shared_ptr
//	
//  auto_ptr �� tr1::shared_ptr ���߶������������������� delete ������ delete[] ����
//		�ڶ�̬������õ� array ����ʹ�� auto_ptr �� tr1::shared_ptr ���Ǻ�����

// 1.Ϊ��ֹ��Դй¶����ʹ�� RAII ���������ڹ��캯���л����Դ���������������ͷ���Դ
// 2.��������ʹ�õ� RAII classes �ֱ��� tr1::shared_ptr �� auto_ptr ��ǰ��ͨ���ǽϼ�ѡ����Ϊ copy ��Ϊ�Ƚ�ֱ��
//		��ѡ�� auto_ptr �����ƶ�����ʹ��(��������)ָ�� null



// ����14 ����Դ��������С�� copying ��Ϊ
// ��Դȡ��ʱ�����ǳ�ʼ��ʱ�� (Resource Acquisition Is Initialization;RAII)
//  ��Դ������ (resourse handlers) class �Ļ����ṹ�� RAII ����֧��
//	Ҳ���� ����Դ�ڹ����ڼ��ã��������ڼ��ͷš�

// ÿһλ RAII class ����һ����Ҫ��ԣ���һ�� RAII ���󱻸��ƣ��ᷢ��ʲô��
//   1.��ֹ����
//		�� copying ��������Ϊ private
//	 2.�Եײ���Դʹ�� ���ü�����
//		ͨ��ֻҪ�ں�һ�� tr1::shared_ptr ��Ա������RAII classes ���ʵ�ֳ� reference-counting copying ��Ϊ
//	 3.���Ƶײ���Դ
//		�ڴ�����¸�����Դ�������Ӧ��ͬʱҲ�������������Դ��Ҳ���ǽ��� ��ȿ���
//	 4.ת�Ƶײ���Դ��ӵ��Ȩ
//		ĳЩ����ϣ����Զֻ��һ�� RAII ����ָ��һ��δ�ӹ���Դ����ʹ RAII ���󱻸�����Ȼ��ˣ�
//		��ʱ��Դ��ӵ��Ȩ��ӱ�������ת�Ƶ�Ŀ����

// ����15 ����Դ���������ṩ��ԭʼ��Դ�ķ���
//	APIs ����Ҫ�����ԭʼ��Դ������ÿһ�� RAII class Ӧ���ṩһ����ȡ���������Դ���İ취
//  ��ԭʼ��Դ�ķ��ʿ��ܾ�����ʽת������ʽת����һ�������ʽת���Ƚϰ�ȫ������ʽת���Կͻ��ȽϷ���

class CFont
{
public:
	explicit CFont(const std::string* name)
		: m_pName(name)
	{
	};
	~CFont()
	{
		delete m_pName;
		m_pName = NULL;
	};

public:
	// �ṩ��ʽת������
	const std::string* get() const
	{
		return m_pName;
	};
	// ��ʽת�������� �ṹΪ�� ����() 
	operator const std::string* () const
	{
		return m_pName;
	}
private:
	const std::string* m_pName;
};

