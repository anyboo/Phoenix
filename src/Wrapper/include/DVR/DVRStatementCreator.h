#pragma once
#include "DVR.h"
#include "DVR/DVRSessionImpl.h"
#include "DVR/DVRStatement.h"
#include "Poco/AutoPtr.h"


namespace DVR {

class DVR_API DVRStatementCreator
	/// A DVRStatementCreator creates Statements.
{
public:
	DVRStatementCreator();
		/// Creates an unitialized DVRStatementCreator.
		
	DVRStatementCreator(Poco::AutoPtr<DVRSessionImpl> ptrImpl);
		/// Creates a DVRStatementCreator.

	DVRStatementCreator(const DVRStatementCreator& other);
		/// Creates a DVRStatementCreator by copying another one.

	~DVRStatementCreator();
		/// Destroys the DVRStatementCreator.

	DVRStatementCreator& operator = (const DVRStatementCreator& other);
		/// Assignment operator.
		
	void swap(DVRStatementCreator& other);
		/// Swaps the DVRStatementCreator with another one.	
		
	template <typename T>
	DVRStatement operator << (const T& t)
		/// Creates a Statement.
	{
		if (!_ptrImpl->isConnected())
			throw NotConnectedException(_ptrImpl->connectionString());

		Statement stmt(_ptrImpl->createStatementImpl());
		stmt << t;
		return stmt;
	}

private:
	Poco::AutoPtr<DVRSessionImpl> _ptrImpl;
};

} 


