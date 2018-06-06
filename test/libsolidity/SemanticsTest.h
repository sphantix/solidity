/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <test/libsolidity/FormattedScope.h>
#include <test/libsolidity/SolidityExecutionFramework.h>
#include <test/libsolidity/TestCase.h>
#include <libsolidity/interface/Exceptions.h>

#include <iosfwd>
#include <string>
#include <vector>
#include <utility>

namespace dev
{
namespace solidity
{
namespace test
{

class SemanticsTest: SolidityExecutionFramework, public TestCase
{
public:
	static std::unique_ptr<TestCase> create(std::string const& _filename)
	{ return std::unique_ptr<TestCase>(new SemanticsTest(_filename)); }
	SemanticsTest(std::string const& _filename);
	virtual ~SemanticsTest() {}

	virtual bool run(std::ostream& _stream, std::string const& _linePrefix = "", bool const _formatted = false) override;

	virtual void printContract(std::ostream& _stream, std::string const& _linePrefix = "", bool const _formatted = false) const override;
	virtual void printUpdatedExpectations(std::ostream& _stream, std::string const& _linePrefix) const override;

	struct ByteRangeFormat
	{
		enum Type {
			Bool,
			String,
			Dec,
			Hash,
			Hex,
			HexString,
			RawBytes,
			SignedDec,
			DynString
		};

		std::size_t length;
		Type type;
		std::string tryFormat(bytes::const_iterator _it, bytes::const_iterator _end) const;
	};

	static std::string bytesToString(
		bytes const& _bytes,
		std::vector<ByteRangeFormat> const& _formatList
	);
	static bytes stringToBytes(
		std::string _list,
		std::vector<ByteRangeFormat>* _formatList = nullptr
	);

	static std::string ipcPath;
private:
	void printCalls(
		bool _actualResults,
		std::ostream& _stream,
		std::string const& _linePrefix,
		bool const _formatted = false
	) const;

	struct SemanticsTestFunctionCall
	{
		std::string signature;
		std::string arguments;
		bytes argumentBytes;
		u256 value;
		std::string expectedResult;
		bytes expectedBytes;
		std::vector<ByteRangeFormat> expectedFormat;
	};

	static std::vector<SemanticsTestFunctionCall> parseCalls(std::istream& _stream);


	std::string m_source;
	std::vector<SemanticsTestFunctionCall> m_calls;
	std::vector<bytes> m_results;
};

}
}
}
