
// util_funcs.h

#pragma once

#include "date.h"

#include <imgui.h>
#include <string>
#include <vector>

// 将uint64_t类型的时间转换为Date类型
Date
uint64_time_to_date(uint64_t time);

// 将Date类型的时间转换为uint64_t类型
uint64_t
date_to_uint64_time(Date date);

std::string
date_to_string(const Date& date);

std::string
parse_train_status(int status);

ImVec4
parse_train_status_color(int status);

bool
InputTime(const char* label, Date* time);

uint32_t
float_to_uint32_price(float price);

float
uint32_price_to_float(uint32_t price);

std::string
uint32_price_to_string(uint32_t price);
