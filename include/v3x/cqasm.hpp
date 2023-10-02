/**
 * \file
 * Main include file for parsing v3x files.
 */

#pragma once

#include "cqasm-tree.hpp"
#include "v1x/cqasm-analyzer.hpp"
#include "v1x/cqasm-semantic.hpp"


/**
 * Toplevel namespace with entry points for the new API.
 */
namespace cqasm {

/**
 * Namespace for the "new" cQASM 3.x API.
 * Its contents are pulled into the main cQASM namespace when you include "cqasm.hpp" for compatibility.
 */
namespace v3x {

/**
 * Parses and analyzes the given file path with the default analyzer,
 * dumping error messages to stderr and throwing an analyzer::AnalysisFailed on failure.
 */
tree::One<cqasm::v1x::semantic::Program> analyze(
    const std::string &file_path,
    const std::string &api_version = "1.0"
);

/**
 * Parses and analyzes the given string with the default analyzer,
 * dumping error messages to stderr and throwing an analyzer::AnalysisFailed on failure.
 * The optional file_name is only used for error messages.
 */
tree::One<cqasm::v1x::semantic::Program> analyze_string(
    const std::string &data,
    const std::string &file_name = "<unknown>",
    const std::string &api_version = "1.0"
);

} // namespace v3x
} // namespace cqasm
