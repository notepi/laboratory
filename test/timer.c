#include "timer.h"
void CTimerLst::AddToLst(CUtilTimer *pfnTimer)
	{
		if(!pfnTimer){
			return;
		}
		if(!m_pfnHead){
			m_pfnHead = pfnTimer;
			m_pfnTail = pfnTimer;
			return;
		}
		if(pfnTimer->m_timExpire < m_pfnHead->m_timExpire){// 插入链表头部
			pfnTimer->m_pfnNext = m_pfnHead;
			m_pfnHead->m_pfnPrev = pfnTimer;
			m_pfnHead = pfnTimer;
		}
		else{// 插入链表内部
			AddToLst(pfnTimer, m_pfnHead);
		}	
	}
	
void CTimerLst::AddToLst(CUtilTimer *pfnTimer, CUtilTimer *pfnHead)
	{
		CUtilTimer *pfnNext = pfnHead->m_pfnNext;
		CUtilTimer *pfnPrev = pfnHead;
		while(pfnNext)// 插入双向链表
		{
			if(pfnTimer->m_timExpire < pfnNext->m_timExpire){
				pfnTimer->m_pfnNext = pfnNext;
				pfnNext->m_pfnPrev = pfnTimer;
				pfnTimer->pfnPrev = pfnNext->m_pfnPrev;
				pfnPrev->m_pfnNext = pfnTimer;
				break;
			}
			pfnNext = pfnNext->m_pfnNext;
			pfnPrev = pfnNext;
		}
		if(!pfnNext){// 插入链表尾部
			pfnPrev->m_pfnNext = pfnTimer;
			pfnTimer->m_pfnPrev = pfnPrev;
			pfnTimer->m_pfnNext = NULL;
			m_pfnTail = pfnTimer;
		}
	}
	
void CTimerLst::DelFromLst(CUtilTimer *pfnTimer)
	{
		if((pfnTimer == m_pfnHead) && (pfnTimer == m_pfnTail)){// 只有一个数据
			m_pfnHead = NULL;
			m_pfnTail = NULL;
		}
		if(pfnTimer == m_pfnHead){
			pfnTimer->m_pfnNext = m_pfnHead;
			m_pfnHead = pfnTimer;
			m_pfnHead->m_pfnPrev = NULL;
		}
	}
	
void DeleteTimerDate(struct CLIENT_DATE *pfsTimer)
{
	delete(pfsTimer);
}