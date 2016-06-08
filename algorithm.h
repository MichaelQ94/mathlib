#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <cstddef>

namespace Math {
	template<typename T>
	class IncreasingSequence {
		typedef T (*seq_func)(size_t);

		std::vector<T> m_sequence;
		seq_func m_function;
		const size_t m_min_index;
		size_t m_index;
		
		public:
			IncreasingSequence(seq_func, size_t minIndex = 0);
			const T& next();
			void extend(const T&);
			const T& operator()(size_t);
			size_t index() const;
			size_t min_index() const;
			bool contains(const T&);
	};

	template<typename T, typename FuncType> 
	std::vector<T> filter(const std::vector<T>&, FuncType&&);
	
	template<typename T, typename FuncType>
	std::vector<T> map(const std::vector<T>&, FuncType&&);

	template<typename T, typename FuncType>
	T reduce(const std::vector<T>&, FuncType&&);

	template<typename T>
	std::vector<std::vector<T> > permutations(std::vector<T>&, size_t size);

	template<typename T>
	std::vector<std::vector<T> > permutations(std::vector<T>&);
	
	template<typename T>
	bool binary_search(const std::vector<T>&, const T&);
}

#include "algorithm.tpp"

#endif
