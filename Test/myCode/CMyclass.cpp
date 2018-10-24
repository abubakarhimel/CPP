#include "CMyclass.h"
#include<iostream>

using namespace std;


CMyclass::CMyclass(float l, float w){

	setValue(l,w);

}

void CMyclass::setValue(float l, float w)
{
	m_length =l;
	m_width = w;
}



float CMyclass::Rectangle()
{
	return m_length*m_width;
}
