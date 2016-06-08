#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <cstddef>

namespace Math {
	template<typename T>
	struct UnaryPredicate {
	public:
		typedef bool (*UnaryPredicate_ptr)(const T&);
	
	private:
		UnaryPredicate_ptr unary_predicate;
		UnaryPredicate();
		constexpr static bool ReturnTrue(const T &val) { return true; }
		constexpr static bool ReturnFalse(const T &val) { return false; }
	
	public:
		static UnaryPredicate<T> True;
		static UnaryPredicate<T> False;
		
		UnaryPredicate(UnaryPredicate_ptr);
		bool operator()(const T&);
	};

	template<typename T>
	struct BinaryPredicate {
	public:
		typedef bool (*BinaryPredicate_ptr)(const T&, const T&);

	private:
		BinaryPredicate_ptr binary_predicate;
		BinaryPredicate();

	public:
		BinaryPredicate(BinaryPredicate_ptr);
		bool operator()(const T&, const T&);
	};
	
	template<typename T>
	struct MapFunction {
	public:
		typedef T (*MapFunction_ptr)(const T&);
	
	private:
		MapFunction_ptr map_function;
		MapFunction();

	public:
		MapFunction(MapFunction_ptr);
		T operator()(const T&);
	};

	template<typename T>
	struct Accumulator {
	public:
		typedef T (*Accumulator_ptr)(const T&, const T&);

	private:
		Accumulator_ptr accumulator;
		Accumulator();

	public:
		Accumulator(Accumulator_ptr);
		T operator()(const T&, const T&);
	};

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

	template<typename T> 
	std::vector<T> filter(const std::vector<T>&, Math::UnaryPredicate<T>);
	
	template<typename T>
	std::vector<T> map(const std::vector<T>&, Math::MapFunction<T>);

	template<typename T>
	T reduce(const std::vector<T>&, Math::Accumulator<T>);

	template<typename T>
	std::vector<std::vector<T> > permutations(std::vector<T>&, size_t size);

	template<typename T>
	std::vector<std::vector<T> > permutations(std::vector<T>&);
	
	template<typename T>
	bool binary_search(const std::vector<T>&, const T&);
}

#include "algorithm.tpp"

#endif
