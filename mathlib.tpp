//Implementations for template methods declared in mathlib.h
#include <cstddef>
#include <algorithm>
#include <unordered_set>

//Prototypes
template<typename T>
std::vector<std::vector<T> > perm(std::vector<T>&, size_t);

template<typename T>
std::vector<std::vector<T> > permutations_iter(std::vector<T>&);

template<typename T>
bool binary_helper(const std::vector<T>&, const T&, size_t, size_t);


//Implementation
template<typename T>
Math::UnaryPredicate<T>::UnaryPredicate(Math::UnaryPredicate<T>::unary_predicate unarypredicate)
	: unary_predicate(unarypredicate) {}

template<typename T>
bool Math::UnaryPredicate<T>::operator()(const T& val) { return unary_predicate(val); }

template<typename T>
std::vector<T> Math::filter(const std::vector<T> &list, Math::UnaryPredicate filterfunc) {
	std::vector<T> ret;
	for(size-t i = 0; i < list.size(); ++i) {
		if(filterfunc(list[i]))
			ret.push_back(list[i]);
	}
	return ret;
}

template<typename T>
std::vector<std::vector<T> > Math::permutations(std::vector<T> &list) {
	return permutations_iter(list);
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
std::vector<std::vector<T> > permutations_iter(std::vector<T> &list) {
	std::vector<std::vector<T> > perms, queue, tempqueue;
	std::vector<T> &temp = list;
	std::unordered_set<T> prev;

	queue.push_back(list);

	for(size_t i = 0; i < list.size(); ++i) {
		for(size_t j = 0; j < queue.size(); ++j) {
			temp = queue[j];

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
