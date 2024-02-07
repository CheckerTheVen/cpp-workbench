namespace workbench {
	template <class Key, class Value>
	class KeyValuePair {
	private:
		Key keyvar;
		Value valuevar;

	public:
		KeyValuePair(const Key&, const Value&);

		Key key();
		Value value();
	};
	
	template <class Key, class Value, bool multiple = false, bool extendable = true, bool removable = false>
	class Dictionary {
	private:
		KeyValuePair<Key, Value>** entries;
		static constexpr int initial = 16;
		static constexpr int maximum = 65536;
		int length;
		int capacity;

		void insert(const int, const KeyValuePair<Key, Value>&);
		void extend();

	public:
		Dictionary();
		Dictionary(const int, bool, bool, bool);
		~Dictionary();

		bool exists(const Key&);
		int indexOf(const Key&);

		KeyValuePair<Key, Value> get(const Key&);
		KeyValuePair<Key, Value> get(const int);

		void add(const KeyValuePair<Key, Value>&);
		void add(const Key&, const Value&);
		void replace(const Key&, const KeyValuePair<Key, Value>&);
		void replace(const Key&, const Key&, const Value&);
		void replace(const int, const KeyValuePair<Key, Value>&);
		void replace(const int, const Key&, const Value&);
		void remove(const Key&);
		void remove(const int);
	};

	template <typename Key, typename Value>
	using IndexableDictionary = Dictionary<Key, Value, false, false>;
}

template <class Key, class Value>
workbench::KeyValuePair<Key, Value>::KeyValuePair(const Key& key, const Value& value) :
	keyvar(key),
	valuevar(value) { }

template <class Key, class Value>
Key workbench::KeyValuePair<Key, Value>::key() {
	return keyvar;
}

template <class Key, class Value>
Value workbench::KeyValuePair<Key, Value>::value() {
	return valuevar;
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
workbench::Dictionary<Key, Value, multiple, extendable, removable>::Dictionary() :
	Dictionary(initial) { }

template <class Key, class Value, bool multiple, bool extendable, bool removable>
workbench::Dictionary<Key, Value, multiple, extendable, removable>::Dictionary(const int intitial, bool multiple, bool extendable, bool removable) :
	entries(new workbench::KeyValuePair<Key, Value>*[initial]) { }

template <class Key, class Value, bool multiple, bool extendable, bool removable>
workbench::Dictionary<Key, Value, multiple, extendable, removable>::~Dictionary() {
	delete entries;
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
void workbench::Dictionary<Key, Value, multiple, extendable, removable>::insert(const int index, const KeyValuePair<Key, Value>& entry) {
	entries[index] = entry;
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
void workbench::Dictionary<Key, Value, multiple, extendable, removable>::extend() {

}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
bool workbench::Dictionary<Key, Value, multiple, extendable, removable>::exists(const Key& key) {
	return indexOf(key) <= 0;
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
int workbench::Dictionary<Key, Value, multiple, extendable, removable>::indexOf(const Key& key) {
	for (int i = 0; i < length; i++) {
		if (*(entries[i]).key() == key) return i;
	}
	return -1;
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
workbench::KeyValuePair<Key, Value> workbench::Dictionary<Key, Value, multiple, extendable, removable>::get(const Key& key) {
	return get(indexOf(key));
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
workbench::KeyValuePair<Key, Value> workbench::Dictionary<Key, Value, multiple, extendable, removable>::get(const int index) {
	if (index >= length || index < 0) return nullptr;
	return *(entries[index]);
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
void workbench::Dictionary<Key, Value, multiple, extendable, removable>::add(const KeyValuePair<Key, Value>& entry) {
	insert(length++, entry);
}

template <class Key, class Value, bool multiple, bool extendable, bool removable>
void workbench::Dictionary<Key, Value, multiple, extendable, removable>::add(const Key& key, const Value& value) {
	insert(length++, KeyValuePair<Key, Value>(key, value));
}

