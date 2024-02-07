#pragma once

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