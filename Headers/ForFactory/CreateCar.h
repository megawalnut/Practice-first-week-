#pragma once

#include "Creator.h"

class CreateCar : public Creator {
	public:
		std::unique_ptr<Transport> create(
            const std::string& brandTrans, 
			const std::string& modelTrans, 
			int yearTrans, 
			double weightTrans) const override;

		~CreateCar() = default;
};