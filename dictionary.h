namespace workbench {
	template <class Key, class Value>
	struct KeyValuePair {
	private:
		const Key* keyvar;
		const Value* valuevar;

	public:
		KeyValuePair(const Key&, const Value&);
		~KeyValuePair();

		Key* key();
		Value* value();
	};

	template <class Key, class Value, bool uniquevar = false>
	class Dictionary {
	private:
		static const int initialCapacity = 16;

		const KeyValuePair<Key, Value>* entries;
		int capacity;
		int length = 0;

		bool unique(const Key&);

	public:
		Dictionary();
		Dictionary(const int);
		~Dictionary();
		
		void add(const Key&, const Value&);
		void add(const KeyValuePair<Key, Value>&);
		KeyValuePair<Key, Value>* get(const Key&);
		int size();
	};
}