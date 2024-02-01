namespace workbench {
	template <class Key, class Value>
	struct KeyValuePair {
	private:
		const Key* key;
		const Value* value;

	public:
		KeyValuePair(const Key&, const Value&);
		~KeyValuePair();

		Key* key();
		Value* value();
	};

	template <class Key, class Value, bool unique = false>
	class Dictionary {
	private:
		static const int initialCapacity = 16;

		const KeyValuePair<Key, Value>* entries;
		int capacity;
		int length = 0;

	public:
		Dictionary();
		Dictionary(const int);
		~Dictionary();

		void add(const Key&, const Value&);
		Value get(const Key&);
		int size();
	};
}