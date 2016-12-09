#ifndef _TIMER_H_
#define _TIMER_H_
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "timer.h"

#define TBUFFER_SIZE 1024
class CUtilTimer
	{
		public:
			CUtilTimer() :m_pfnPrev(NULL), m_pfnNext(NULL){};
		
		public:
			time_t m_timExpire;
			void(*OnHandClinet)(struct CLIENT_DATE *pfsClient);
			CUtilTimer *m_pfnPrev;
			CUtilTimer *m_pfnNext;   
	};


class CTimerLst
	{
		public:
			CTimerLst(): m_pfnHead(NULL), m_pfnTail(NULL){};
		public:
			void AddToLst(CUtilTimer *pfnTimer);
			void AddToLst(CUtilTimer *pfnTimer, CUtilTimer *pfnHead);
			void DelFromLst(CUtilTimer *pfnTimer);	
		private:
			CUtilTimer *m_pfnHead;
			CUtilTimer *m_pfnTail;	
	};
	
struct CLIENT_DATE{
//	sockaddr_in m_saAddress;
	int m_nSockfd;
	char m_gcBuff[TBUFFER_SIZE];
	CUtilTimer *m_pfnTimer;
};
void DeleteTimerDate(struct CLIENT_DATE *pfsTimer);
#endif