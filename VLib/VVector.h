#pragma once

#include <initializer_list>

namespace VLib
{
	template<class T>
	class VVector
	{
	public:
		VVector();
		VVector(T* const data, size_t len);
		VVector(VVector const &othr);
		VVector(size_t count);
		VVector(size_t count, T const &defval);
		VVector(std::initializer_list<T> const &init);

		~VVector();

		VVector extract(size_t begin, size_t len);

		VVector& sort();

		T* data() const;

		T& operator[](size_t index);
		T operator[](size_t index) const;

		void append(VVector const &othr);
		void append(T* const data, size_t len);

		size_t size() const;

		VVector& reverse();

		VVector& operator=(VVector const &othr);

		bool operator==(VVector const &othr);
		bool operator!=(VVector const &othr);

		VVector& operator+=(VVector const &othr);
		VVector& operator+=(T const &element);

	protected:
		T *m_data = nullptr;
		size_t m_len;
	};
	
	template<class T>
	VVector<T> reverse(VVector<T> othr);
	template<class T>
	VVector<T> extract(VVector<T> const &othr, size_t begin, size_t len);
	template<class T>
	VVector<T> sort(VVector<T> othr);



	template<class T>
	inline VVector<T>::VVector()
	{
		m_len = 0;
		m_data = nullptr;
	}
	template<class T>
	inline VVector<T>::VVector(T * const data, size_t len)
	{
		m_len = len;
		m_data = new T[len];
		for (size_t i = 0; i < len; i++)
		{
			m_data[i] = data[i];
		}
	}
	template<class T>
	inline VVector<T>::VVector(VVector const & othr)
	{
		m_len = othr.size();
		m_data = new T[m_len];
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = othr.m_data()[i];
		}
	}
	template<class T>
	inline VVector<T>::VVector(size_t count)
	{
		m_len = count;
		m_data = new T[m_len];
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = T(0);
		}
	}
	template<class T>
	inline VVector<T>::VVector(size_t count, T const & defval)
	{
		m_len = count;
		m_data = new T[m_len];
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = defval;
		}
	}
	template<class T>
	inline VVector<T>::VVector(std::initializer_list<T> const & init)
	{
		m_len = init.size();
		m_data = new T[m_len];
		for (size_t i = 0;i<m_len;i++)
		{
			m_data[i] = *(init.begin()+i);
		}
	}
	template<class T>
	inline VVector<T>::~VVector()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;
		}
		m_len = 0;
	}
	template<class T>
	inline VVector<T> VVector<T>::extract(size_t begin, size_t len)
	{
		if (begin + len > m_len)
		{
			len = this->m_len - begin;
		}
		T* tmp;
		tmp = new T[len];
		for (size_t i = 0; i < len; i++)
		{
			tmp[i] = m_data[begin + i];
		}
		return VVector<T>(tmp, len);
	}
	template<class T>
	inline VVector<T> & VVector<T>::sort()
	{
		for (size_t i = 0; i < m_len-1; i++)
		{
			for (size_t j = 0; j < m_len-1; j++)
			{
				if (m_data[j] > m_data[j + 1])
					{
						T tmp = m_data[j];
						m_data[j] = m_data[j+1];
						m_data[j+1] = tmp;
					}
			}
		}
		return *this;
	}
	template<class T>
	inline T * VVector<T>::data() const
	{
		return m_data;
	}
	template<class T>
	inline T & VVector<T>::operator[](size_t index)
	{
		if (index < m_len)
		{
			return m_data[index];
		}
	}
	template<class T>
	inline T VVector<T>::operator[](size_t index) const
	{
		if (index < m_len)
		{
			return m_data[index];
		}
	}
	template<class T>
	inline void VVector<T>::append(VVector const & othr)
	{
		if (m_data == nullptr)
		{
			this->operator=(othr);
			return;
		}
		else if (othr.data() == nullptr)
		{
			return;
		}
		else
		{
			T* tmp;
			tmp = m_data;
			m_data = new T[m_len + othr.size()];
			for (size_t i = 0; i < m_len; i++)
			{
				m_data[i] = tmp[i];
			}
			for (size_t i = 0; i < othr.size(); i++)
			{
				m_data[i + m_len] = othr.data()[i];
			}
			m_len += othr.size();
			delete[] tmp;
		}

	}
	template<class T>
	inline void VVector<T>::append(T * const data, size_t len)
	{
		if (m_data == nullptr)
		{
			this->operator=(VVector<T>(data,len));
			return;
		}
		else
		{
			T* tmp;
			tmp = m_data;
			m_data = new T[m_len + len];
			for (size_t i = 0; i < m_len; i++)
			{
				m_data[i] = tmp[i];
			}
			for (size_t i = 0; i < len; i++)
			{
				m_data[i + m_len] = data[i];
			}
			m_len += len;
			delete[] tmp;
		}
	}
	template<class T>
	inline size_t VVector<T>::size() const
	{
		return m_len;
	}
	template<class T>
	inline VVector<T> & VVector<T>::reverse()
	{
		T* tmp;
		tmp = new T[m_len];
		for (size_t i = 0; i < m_len; i++)
		{
			tmp[i] = m_data[i];
		}
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = tmp[m_len - 1 - i];
		}
		return *this;
	}
	template<class T>
	inline VVector<T> & VVector<T>::operator=(VVector const & othr)
	{
		this->~VVector();
		m_len = othr.size();
		m_data = new T[m_len];
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = othr.data()[i];
		}
		return *this;
	}
	template<class T>
	inline bool VVector<T>::operator==(VVector const & othr)
	{
		if (m_len != othr.size())
			return false;
		for (size_t i = 0; i < m_len; i++)
		{
			if (m_data[i] != othr[i])
				return false;
		}
		return true;
	}
	template<class T>
	inline bool VVector<T>::operator!=(VVector const & othr)
	{
		return !this->operator==(othr);
	}
	template<class T>
	inline VVector<T> & VVector<T>::operator+=(VVector const & othr)
	{
		this->append(othr);
		return *this;
	}
	template<class T>
	inline VVector<T> & VVector<T>::operator+=(T const & element)
	{
		T* tmp;
		tmp = m_data;
		m_data = new T[m_len + 1];
		for (size_t i = 0; i < m_len; i++)
		{
			m_data[i] = tmp[i];
		}
		m_data[m_len] = element;
		m_len += 1;
		delete[] tmp;
		return *this;
	}
	template<class T>
	VVector<T> reverse(VVector<T> othr)
	{
		return othr.reverse();
	}
	template<class T>
	VVector<T> extract(VVector<T> const & othr, size_t begin, size_t len)
	{
		return othr.extract(begin,len);
	}
	template<class T>
	VVector<T> sort(VVector<T> othr)
	{
		return othr.sort();
	}
}
