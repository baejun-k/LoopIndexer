#ifndef __LOOP_INDEXER_HPP__
#define __LOOP_INDEXER_HPP__


template<size_t size>
class LoopIndex {
private:
	signed long long m_idx;

public:
	LoopIndex(int idx = 0)
	{
		m_idx = idx;
	}

	operator const size_t()
	{
		if ( this->m_idx < 0 )
		{
			size_t rvIdx = -this->m_idx;
			rvIdx = ( rvIdx - 1 ) % size + 1;
			this->m_idx = size - rvIdx;
		}
		else
		{
			this->m_idx %= size;
		}
		return this->m_idx;
	}

	LoopIndex &Next(size_t num = 1)
	{
		this->m_idx = this->m_idx + num;
		return *this;
	}

	LoopIndex &operator ++()
	{
		this->m_idx = m_idx + 1;
		return *this;
	}

	LoopIndex operator ++(int)
	{
		LoopIndex<size> tmp(*this);
		this->m_idx = m_idx + 1;
		return tmp;
	}

	LoopIndex &operator --()
	{
		this->m_idx = m_idx - 1;
		return *this;
	}

	LoopIndex operator --(int)
	{
		LoopIndex<size> tmp = *this;
		this->m_idx = m_idx - 1;
		return tmp;
	}
};



#endif // !__LOOP_INDEXER_H__

