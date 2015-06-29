#pragma once

#define Game_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)

// ɾ��ָ��
#if !defined(Game_SAFE_DELETE)
#define Game_SAFE_DELETE(p) if((p)) { delete (p); (p)=0; }
#endif

// ɾ��v����,��vector,list,set
#if !defined(Game_SAFE_DELETE_STL_V)
#define Game_SAFE_DELETE_STL_V( STL_V_CONTAINER, container ) \
	for( STL_V_CONTAINER::iterator itForDelete=(container).begin(); itForDelete!=(container).end(); ++itForDelete )\
			{\
		if( *itForDelete != NULL )\
						{\
			delete *itForDelete;\
						}\
			}\
	(container).clear()
#endif

// ɾ��k,v����,��map,unordered_map
#if !defined(Gane_SAFE_DELETE_STL_KV)
#define Gane_SAFE_DELETE_STL_KV( STL_KV_CONTAINER, container ) \
	for( STL_KV_CONTAINER::iterator itForDelete=(container).begin(); itForDelete!=(container).end(); ++itForDelete )\
			{\
		if( itForDelete->second != NULL )\
						{\
			delete itForDelete->second;\
						}\
			}\
	(container).clear()
#endif