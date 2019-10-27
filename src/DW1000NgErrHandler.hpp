/*
 * MIT License
 * 
 * Copyright (c) 2018 Michele Biondi, Andrea Salvatori
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#pragma once

enum class DW1000NgStatus {
    NO_ERROR,
    INPUT_ERROR,
    INTERNAL_ERROR,
    CONFIGURATION_ERROR,
    FRAME_LENGTH_EXCEEDED_ERROR
};

class DW1000NgErrHandler 
{
private:
    DW1000NgStatus _lastState;
    DW1000NgStatus _state;

public:
    /**
	 * default Constructor
	 */
    DW1000NgErrHandler(int level);
    /**
	 * default Destructor
	 */
    ~DW1000NgErrHandler();
    
    void catchErr(DW1000NgStatus status, char msg[]);

    DW1000NgStatus getLastState();

    DW1000NgStatus getState();
};

extern DW1000NgErrHandler ErrHandler;