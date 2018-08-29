#pragma once
#include <list>
template <typename ...TArgs>
class Event {
public:
	typedef void(*MethodHandler)(TArgs... args);
private:
	enum class Type
	{
		Class, Static
	};
	struct Base {
		Type type;
		virtual void Process(TArgs... args) = 0;
	};
	struct Static : Base {
		MethodHandler method;
		Static(MethodHandler method) : Base{ Type::Static }, method{ method } {}
		virtual void Process(TArgs... args)override {
			method(args...);
		}
	};
	template <typename TClass, typename TMethod>
	struct Class : Base {
		TClass* object;
		TMethod method;
		Class(TClass* object, TMethod method)
			: object{ object }, method{ method }{}
		virtual void Process(TArgs... args)override {
			(object->*method)(args...);
		}
	};
	std::list<Base*> items;

public:
	void Add(MethodHandler handler) {
		Static* item = new Static(handler);
		items.push_back(item);
	}
	template <typename TClass, typename TMethod>
	void Add(TClass* object, TMethod method) {
		Class<TClass, TMethod>* item = new Class<TClass, TMethod>(object, method);
		items.push_back(item);
	}
	void Remove(MethodHandler handler) {
		for (auto item : items) {
			if (item->type == Type::Static && item->method == handler) {
				items.remove(item);
				delete item;
			}
		}
	}
	template <typename TClass, typename TMethod>
	void Remove(TClass* object, TMethod method) {
		for (auto item : items) {
			if (item->type == Type::Class && item->object == object && item->method == method) {
				items.remove(item);
				delete item;
			}
		}
	}
	void Process(TArgs... args) {
		for (auto item : items) {
			item->Process(args...);
		}
	}
};