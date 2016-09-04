#pragma once
#include "DVR/DVR.h"
#include "DVR/DVRStatementImpl.h"
#include <Poco/Mutex.h>

namespace DVR {
	class DVRSession;
	class DVR_API DVRStatement
	{
	public:
		DVRStatement(DVRStatementImpl::Ptr pImpl);
		explicit DVRStatement(DVRSession& session);
		
		~DVRStatement();

		DVRStatement(const DVRStatement& stmt);
		DVRStatement& operator = (const DVRStatement& stmt);
		DVRStatement& reset(DVRSession& session);
		void swap(DVRStatement& other);

		template <typename T>
		DVRStatement& operator << (const T& t)
		{
			_pImpl->add(t);
			return *this;
		}

	protected:
		typedef DVRStatementImpl::Ptr ImplPtr;
		ImplPtr impl() const;
		DVRSession session();
		
	private:
		DVRStatementImpl::Ptr _pImpl;
	};

}