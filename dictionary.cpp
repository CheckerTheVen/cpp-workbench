#include "dictionary.h"

/// <summary>
/// Instantiates 
/// </summary>
template<class Key, class Value>
workbench::KeyValuePair<Key, Value>::KeyValuePair(const Key& key, const Value& value) {
	this->keyvar = key;
	this->valuevar = value;
}

template<class Key, class Value>
workbench::KeyValuePair<Key, Value>::~KeyValuePair() {
	delete keyvar;
	delete valuevar;
}

template<class Key, class Value>
Key* workbench::KeyValuePair<Key, Value>::key() {
	return this->keyvar;
}

template<class Key, class Value>
Value* workbench::KeyValuePair<Key, Value>::value() {
	return this->valuevar;
}

template<class Key, class Value, bool uniquevar>
workbench::Dictionary<Key, Value, uniquevar>::Dictionary() :
	Dictionary(initialCapacity) { }

template<class Key, class Value, bool uniquevar>
workbench::Dictionary<Key, Value, uniquevar>::Dictionary(int initial) :
	capacity(initial),
	entries(new const KeyValuePair<Key, Value>*[initial]) { }

template<class Key, class Value, bool uniquevar>
workbench::Dictionary<Key, Value, uniquevar>::~Dictionary() {
	delete entries;
}

template<class Key, class Value, bool uniquevar>
bool workbench::Dictionary<Key, Value, uniquevar>::unique(const Key& key) {
	if (!uniquevar) return true;

	for (int i = 0; i < length; i++) {
		if (*((*(entries[i])).key()) == key) return false;
	}

	return true;
}

template<class Key, class Value, bool uniquevar>
void workbench::Dictionary<Key, Value, uniquevar>::add(const Key& key, const Value& value) {
	if (!unique(key)) return;

	entries[length] = new KeyValuePair<Key, Value>(key, value);
	length++;
}

template<class Key, class Value, bool uniquevar>
workbench::KeyValuePair<Key, Value>* workbench::Dictionary<Key, Value, uniquevar>::get(const Key& key) {
	for (int i = 0; i < length; i++) {
		if (*(keys[i]) == key) return *(values[i]);
	}
	return nullptr;
}

template<class Key, class Value, bool uniquevar>
int workbench::Dictionary<Key, Value, uniquevar>::size() {
	return this->length;
}