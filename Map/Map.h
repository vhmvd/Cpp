#ifndef Map_h
#define Map_h

#include <iostream>
#include <string>

using std::cout;

template<class K, class V>
struct Map
{
	K keys[100]{};
	V values[100]{};
	int size;
	Map()
	{
		size = 0; //does what line 19-23 does
	}
};

//template<class K, class V>
//void Initialize(Map<K, V>& map)
//{
//	map.size = 0;
//}

template<class K, class V>
void Put(Map<K, V>& map, const K& key, const V& value)
{
	for (int i = 0; i < 100; i++)
	{
		if (key == map.keys[i])
		{
			return;
		}
	}
	map.keys[map.size] = key;
	map.values[map.size] = value;
	map.size++;
}

template<class K, class V>
V& Get(Map<K, V>& map, const K& key)
{
	for (int i = 0; i <= map.size; i++)
	{
		if (key == map.keys[i])
		{
			return map.values[i];
		}
	}
	throw "Key was not found!\n";
}

template<class K, class V>
bool Contains(Map<K, V>& map, const K& key)
{
	if (key)
	{
		for (int i = 0; i <= map.size; i++)
		{
			if (key == map.keys[i])
			{
				return true;
			}
		}
	}
	return false;
}

template<class K, class V>
void Remove(Map<K, V>& map, const K& key)
{
	if (key)
	{
		for (int i = 0; i <= map.size; i++)
		{
			if (key == map.keys[i])
			{
				for (int j = i; j <= map.size; j++)
				{
					if (j == 99)
					{
						map.keys[j] = {};
						map.values[j] = {};
						return;
					}
					map.keys[j] = map.keys[j + 1];
					map.values[j] = map.values[j + 1];
				}
				map.size--;
				return;
			}
		}
	}
}

#endif