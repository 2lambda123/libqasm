#!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Usage: regenerate_parser.sh <INPUT FOLDER> <OUTPUT FOLDER> <ANTLR_JAR_LOCATION>"
    echo "Where:"
    echo "    INPUT_FOLDER: folder containing the grammar files."
    echo "    OUTPUT_FOLDER: folder where generated files will be left."
    echo "    ANTLR_JAR_LOCATION: path to antlr jar file."
    echo "Example:"
    echo "    regenerate_parser.sh ../src/v3 ../build/Debug/src/v3 ../third_party/antlr/antlr-4.13.0-complete.jar"
fi

if ! command -v java &> /dev/null; then
    echo "Please install Java JRE: sudo apt-get update && sudo apt-get -y install default-jre"
    exit 2
fi

input_folder=$1
output_folder=$2
antlr_jar_location=$3

export CLASSPATH=".:$antlr_jar_location:$CLASSPATH"

set -x  # echo on
java -jar $antlr_jar_location -Xexact-output-dir -o $output_folder -Dlanguage=Cpp $input_folder/*.g4
