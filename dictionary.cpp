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
		KeyValuePair<Key, Value>&* entries;
		static constexpr int initial = 16;
		static constexpr int maximum = 65536;
		int length;
		int capacity;

		void insert(const int, const KeyValuePair<Key, Value>&);
		void extend();

	public:
		Dictionary();
		Dictionary(const int, bool, bool, bool);

		void add(const KeyValuePair<Key, Value>&);
		void add(const Key&, const Value&);
		void replace(const Key&, const KeyValuePair<Key, Value>&);
		void replace(const Key&, const Key&, const Value&);
		void replace(const int, const KeyValuePair<Key, Value>&);
		void replace(const int, const Key&, const Value&);
		void remove(const Key&);
		void remove(const int);

		KeyValuePair<Key, Value>& get(const Key&);
		KeyValuePair<Key, Value>& get(const int);
		bool exists(const Key&);
		bool exists(const int);
		int indexOf(const Key&);
		int indexOf(const int);

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
