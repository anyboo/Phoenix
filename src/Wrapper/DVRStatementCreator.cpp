#include "DVR/DVRStatementCreator.h"
#include <algorithm>


namespace DVR {


DVRStatementCreator::DVRStatementCreator()
{
}


DVRStatementCreator::DVRStatementCreator(Poco::AutoPtr<DVRSessionImpl> ptrImpl):
	_ptrImpl(ptrImpl)
{
}


DVRStatementCreator::DVRStatementCreator(const DVRStatementCreator& other):
	_ptrImpl(other._ptrImpl)
{
}


DVRStatementCreator& DVRStatementCreator::operator = (const DVRStatementCreator& other)
{
	DVRStatementCreator tmp(other);
	swap(tmp);
	return *this;
}


void DVRStatementCreator::swap(DVRStatementCreator& other)
{
	using std::swap;
	swap(_ptrImpl, other._ptrImpl);
}


DVRStatementCreator::~DVRStatementCreator()
{
}


}
