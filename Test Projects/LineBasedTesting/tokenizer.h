/*
	tokenizer.h
	Andrew Ng
	Oct 15 2019
	header for string/token functions for hw 4
*/

#pragma once

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

bool ReadLine(std::string& str);

unsigned StringToTokensWS(std::vector<std::string>& tokens, std::string& str);

void EvaluateTokens(std::vector<std::string>& tokens);

long double EvalInside(const size_t& left, const size_t& right, std::vector<std::string>& tokens);

void EvaluateTokens2(std::vector<std::string>& tokens);

void AnalyzeTokens(const std::vector<std::string>& tokens);

#endif