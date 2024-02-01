#include "dictionary.h"

template<class Key, class Value>
workbench::KeyValuePair<Key, Value>::KeyValuePair(const Key& key, const Value& value) {
	this->key = key;
	this->value = value;
}

template<class Key, class Value>
workbench::KeyValuePair<Key, Value>::~KeyValuePair() {
	delete key;
	delete value;
}

template<class Key, class Value>
Key* workbench::KeyValuePair<Key, Value>::key() {
	return this->key;
}

template<class Key, class Value>
Value* workbench::KeyValuePair<Key, Value>::value() {
	return this->value;
}

template<class Key, class Value, bool unique>
workbench::Dictionary<Key, Value, unique>::Dictionary() :
	Dictionary(initialCapacity) { }

template<class Key, class Value, bool unique>
workbench::Dictionary<Key, Value, unique>::Dictionary(int initial) :
	capacity(initial),
	keys(new const Key* [initial]),
	values(new const Value* [initial]) { }

template<class Key, class Value, bool unique>
workbench::Dictionary<Key, Value, unique>::~Dictionary() {
	delete keys;
	delete values;
}

template<class Key, class Value, bool unique>
void workbench::Dictionary<Key, Value, unique>::add(const Key& key, const Value& value) {
	for (int i = 0; i < length; i++) {
		if (*(keys[i]) == key) {
			return;
		}
	}

	keys[length] = &key;
	values[length] = &value;
	length++;
}

template<class Key, class Value, bool unique>
Value workbench::Dictionary<Key, Value, unique>::get(const Key& key) {
	for (int i = 0; i < length; i++) {
		if (*(keys[i]) == key) {
			return *(values[i]);
		}
	}
	return nullptr;
}

template<class Key, class Value, bool unique>
int workbench::Dictionary<Key, Value, unique>::size() {
	return this->length;
}