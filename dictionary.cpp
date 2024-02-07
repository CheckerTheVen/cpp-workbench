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
