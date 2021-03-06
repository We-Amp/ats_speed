/** @file

    A brief file description

    @section license License

    Licensed to the Apache Software Foundation (ASF) under one
    or more contributor license agreements.  See the NOTICE file
    distributed with this work for additional information
    regarding copyright ownership.  The ASF licenses this file
    to you under the Apache License, Version 2.0 (the
    "License"); you may not use this file except in compliance
    with the License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef ATS_RESOURCE_INTERCEPT_H
#define ATS_RESOURCE_INTERCEPT_H

#include <string>

#include <ts/ts.h>

#include "net/instaweb/http/public/async_fetch.h"
#include "pagespeed/kernel/http/headers.h"
#include "pagespeed/kernel/base/string_util.h"
#include "pagespeed/kernel/base/string.h"

#include "ats_pagespeed.h"

struct InterceptCtx {
  TSVConn vconn;
  TSIOBuffer req_buffer;
  TSIOBufferReader req_reader;
  TSIOBuffer resp_buffer;
  TSIOBufferReader resp_reader;
  GoogleString *response;
  TransformCtx *request_ctx;
  net_instaweb::RequestHeaders *request_headers;

  InterceptCtx()
    : vconn(NULL),
      req_buffer(NULL),
      req_reader(NULL),
      resp_buffer(NULL),
      resp_reader(NULL),
      response(new GoogleString()),
      request_ctx(NULL),
      request_headers(NULL){};
};

void setup_resource_intercept();

#endif // ATS_INTERCEPT_H
