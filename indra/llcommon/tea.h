/** 
 * @file tea.h
 * @brief tea viewer helper library
 *
 * Copyright (C) 2012 arminweatherwax (at) lavabit.com
 * You can use it under the following license:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef TEA_H
#define TEA_H

#include <string>

class Tea
{
public:
	Tea();
	~Tea();

	static void setCurrency(const std::string& currency);
	static void setRegionCurrency(const std::string& currency);
	static std::string getCurrency() { return sActiveCurrency; }
	static std::string wrapCurrency(const std::string& to_substitute);
	static void wrapCurrency(std::string& to_substitute);
private:
	static std::string sGridCurrency;	// Grid wide default currency symbol eg: L$, G$, D$
	static std::string sRegionCurrency;	// Region currency symbol override; empty string means use grid symbol
	static std::string sActiveCurrency;	// Active currency symbol (Grid if region is empty string)

	static void updateActiveCurrencySymbol();	// Updated on...
							// 	Startup to L$ (default set at top of cpp)
							// 	Login to Grid Currency (see llstartup)
							//	HG teleport to new Grid Currency (hopefully also llstartup)
							//	Entering region with currency module override to Region Currency (see lfsimfeaturehandler)
							// Ideally, this would trigger an update to mark any LLUIStrings with L$
							// symbols but without params to dirty to force re-execution and do any
							// necessary reloads of UI widgets, but llcommon really should include
							// systems from newview, so we've placed this function in lfsimfeaturehandler
							// and call it manually.  Aternatively, we could consider registering
							// that func with Tea to let Tea call it, but for the timebeing, I did
							// not want to complicate Tea which is rather simple.
};

#endif //TEA_H
