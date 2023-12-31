/****************************************************************************
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 Copyright (c) 2019-present Axmol Engine contributors (see AUTHORS.md).
 
 https://axmolengine.github.io/
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __LUA_WEBSOCKET_H__
#define __LUA_WEBSOCKET_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "network/WebSocket.h"

///@cond
class LuaWebSocket: public ax::network::WebSocket, public ax::network::WebSocket::Delegate
{
public:
    ~LuaWebSocket() override;;
    void onOpen(WebSocket* ws) override;
    void onMessage(WebSocket* ws, const WebSocket::Data& data) override;
    void onClose(WebSocket* ws) override;
    void onError(WebSocket* ws, const WebSocket::ErrorCode& error) override;
    
    enum WebSocketScriptHandlerType
    {
        kWebSocketScriptHandlerOpen,
        kWebSocketScriptHandlerMessage,
        kWebSocketScriptHandlerClose,
        kWebSocketScriptHandlerError,
    };
};

TOLUA_API int tolua_web_socket_open(lua_State* tolua_S);
TOLUA_API int register_web_socket_manual(lua_State* tolua_S);
///@endcond

#endif //__LUA_WEBSOCKET_H__
