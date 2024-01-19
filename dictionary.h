#pragma once

namespace workbench {
	template<class Key, class Value>
	class Dictionary {
	private:
		static const int initialCapacity = 16;

		const Key** keys;
		const Value** values;
		int capacity;
		int length = 0;

	public:
		Dictionary() : Dictionary(initialCapacity) {

		}

		Dictionary(const int initial) : capacity(initial), keys(new const Key*[initial]), values(new const Value*[initial]) {

		}

		~Dictionary() {
			delete keys;
			delete values;
		}

		void add(const Key& key, const Value& value) {
			for (int i = 0; i < length; i++) {
				if (*(keys[i]) == key) {
					return;
				}
			}

			keys[length] = &key;
			values[length] = &value;
			length++;
		}

		Value get(const Key& key) {
			for (int i = 0; i < length; i++) {
				if (*(keys[i]) == key) {
					return *(values[i]);
				}
			}
			return nullptr;
		}

		int size() {
			return length;
		}
	};
}
