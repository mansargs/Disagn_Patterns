#pragma once

class Iterator {
	public:
		virtual bool hasNext() const = 0;
		virtual int next() = 0;
		virtual ~Iterator() = default;
};
