//Implementations for template methods declared in mathlib.h
#include <cstddef>
#include <algorithm>
#include <unordered_set>

//Prototypes
template<typename T>
std::vector<std::vector<T> > perm(std::vector<T>&, size_t);

template<typename T>
std::vector<std::vector<T> > permutations_iter(std::vector<T>&, size_t);

template<typename T>
bool binary_helper(const std::vector<T>&, const T&, size_t, size_t);

//Implementation
template<typename T>
Math::UnaryPredicate<T>::UnaryPredicate(Math::UnaryPredicate<T>::UnaryPredicate_ptr unarypredicate)
	: unary_predicate(unarypredicate) {}

template<typename T>
bool Math::UnaryPredicate<T>::operator()(const T& val) { return unary_predicate(val); }

template<typename T>
Math::BinaryPredicate<T>::BinaryPredicate(Math::BinaryPredicate<T>::BinaryPredicate_ptr binarypredicate)
	: binary_predicate(binarypredicate) {}

template<typename T>
bool Math::BinaryPredicate<T>::operator()(const T& val1, const T& val2) { return binary_predicate(val1, val2); }

template<typename T>
Math::MapFunction<T>::MapFunction(Math::MapFunction<T>::MapFunction_ptr mapfunction)
	: map_function(mapfunction) {}

template<typename T>
T Math::MapFunction<T>::operator()(const T& val) { return map_function(val); }

template<typename T>
Math::Accumulator<T>::Accumulator(Math::Accumulator<T>::Accumulator_ptr acc)
	: accumulator(acc) {}

template<typename T>
T Math::Accumulator<T>::operator()(const T& val1, const T& val2) { return accumulator(val1, val2); }

template<typename T>
std::vector<T> Math::filter(const std::vector<T> &list, Math::UnaryPredicate<T> filterfunc) {
	std::vector<T> ret;
	for(size_t i = 0; i < list.size(); ++i)
		if(filterfunc(list[i]))
			ret.push_back(list[i]);
	return ret;
}

template<typename T>
std::vector<T> Math::map(const std::vector<T> &list, Math::MapFunction<T> mapfunction) {
	std::vector<T> ret;
	ret.reserve(list.size());

	for(size_t i = 0; i < list.size(); ++i)
		ret.push_back(mapfunction(list[i]));

	return ret;
}

template<typename T>
T Math::reduce(const std::vector<T> &list, Math::Accumulator<T> accumulator) {
	if(list.size() == 0) return T();

	T ret = list[0];
	for(size_t i = 1; i < list.size(); ++i) {
		ret = accumulator(ret, list[i]);
	}

	return ret;
}

template<typename T>
std::vector<std::vector<T> > Math::permutations(std::vector<T> &list, size_t size) {
	return permutations_iter(list, size);
}

template<typename T>
std::vector<std::vector<T> > Math::permutations(std::vector<T> &list) {
	return permutations_iter(list, list.size());
}

template<typename T>
std::vector<std::vector<T> > perm(std::vector<T> &list, size_t index) {
	std::vector<std::vector<T> > perms;

	if(index >= list.size()) {
		perms.push_back(list);
		return perms;
	}

	std::unordered_set<T> prev;
	std::vector<std::vector<T> > temp;
	
	for(size_t i = index; i < list.size(); ++i) {
		if(prev.insert(list[i]).second) {
			std::swap(list[index], list[i]);
		
			temp = perm(list, index + 1);
			for(size_t j = 0; j < temp.size(); ++j) {
				perms.push_back(temp[j]);
			}

			std::swap(list[index], list[i]);
		}
	}

	return perms;
}

template<typename T>
std::vector<std::vector<T> > permutations_iter(std::vector<T> &list, size_t size) {
	if(size > list.size())
		size = list.size();

	std::vector<std::vector<T> > perms, queue, tempqueue;
	std::vector<T> &temp = list;
	std::unordered_set<T> prev;

	queue.push_back(list);

	//decide the ith element
	for(size_t i = 0; i < size; ++i) {

		//queue contains lists for which elements 0 through (i-1) have been fixed
		for(size_t j = 0; j < queue.size(); ++j) {
			temp = queue[j];

			//fix the element at position i
			for(size_t k = i; k < temp.size(); ++k) {
				if(prev.insert(list[k]).second) {
					std::swap(temp[i], temp[k]);
					tempqueue.push_back(temp);
					std::swap(temp[i], temp[k]);
				}
			}

			prev.clear();
		}
		queue = std::move(tempqueue);
		tempqueue.clear();
	}

	for(size_t i = 0; i < queue.size(); ++i)
		while(queue[i].size() > size)
			queue[i].pop_back();

	return queue;
}

template<typename T>
bool Math::binary_search(const std::vector<T> &list, const T &val) {
	return (list.size() > 0) && binary_helper(list, val, 0, list.size() - 1);
}

template<typename T>
bool binary_helper(const std::vector<T> &list, const T &val, size_t start, size_t end) {
	if(start > end) return false;

	size_t mid = start + ((end - start) / 2);

	if(val < list[mid])
		if(mid == start)
			return false;
		else
			return binary_helper(list, val, start, mid - 1);
	else if (val > list[mid])
		return binary_helper(list, val, mid + 1, end);
	else
		return true;
}

template<typename T>
Math::UnaryPredicate<T> Math::UnaryPredicate<T>::True(&Math::UnaryPredicate<T>::ReturnTrue);

template<typename T>
Math::UnaryPredicate<T> Math::UnaryPredicate<T>::False(&Math::UnaryPredicate<T>::ReturnFalse);
