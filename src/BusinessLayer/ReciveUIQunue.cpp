#include "stdafx.h"
#include "ReciveUIQunue.h"

ReciveUIQunue* ReciveUIQunue::m_pReceiveUIQueue = NULL;

ReciveUIQunue::ReciveUIQunue()
{
}


ReciveUIQunue::~ReciveUIQunue()
{
}

ReciveUIQunue* ReciveUIQunue::GetInstance()
{
	m_pReceiveUIQueue = new ReciveUIQunue;
	return m_pReceiveUIQueue;
}

void ReciveUIQunue::DestroyInstance()
{
	if (NULL != m_pReceiveUIQueue)
	{
		delete m_pReceiveUIQueue;
		m_pReceiveUIQueue = NULL;
	}
}
