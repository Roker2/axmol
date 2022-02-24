/****************************************************************************
Copyright (c) 2015-2017 Chukong Technologies Inc.

https://adxeproject.github.io/

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

#include "flatbuffers/flatbuffers.h"
#include "WidgetReader/SkeletonReader/CSBoneBinary_generated.h"
#include "WidgetReader/NodeReader/NodeReader.h"
#include "CSParseBinary_generated.h"
#include "WidgetReader/SkeletonReader/SkeletonNodeReader.h"
#include "ActionTimeline/CCSkeletonNode.h"

USING_NS_CC;
USING_NS_TIMELINE;
using namespace cocostudio;
using namespace flatbuffers;

IMPLEMENT_CLASS_NODE_READER_INFO(SkeletonNodeReader)

SkeletonNodeReader::SkeletonNodeReader() {}

SkeletonNodeReader::~SkeletonNodeReader() {}

static SkeletonNodeReader* _instanceSkeletonNodeReader = nullptr;

SkeletonNodeReader* SkeletonNodeReader::getInstance()
{
    if (_instanceSkeletonNodeReader == nullptr)
    {
        _instanceSkeletonNodeReader = new SkeletonNodeReader();
    }
    return _instanceSkeletonNodeReader;
}

void SkeletonNodeReader::destroyInstance()
{
    CC_SAFE_DELETE(_instanceSkeletonNodeReader);
}

cocos2d::Node* SkeletonNodeReader::createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions)
{
    auto bone = SkeletonNode::create();

    // self options
    auto options = (flatbuffers::BoneOptions*)nodeOptions;
    setPropsWithFlatBuffers(bone, (Table*)options);

    // super options (node)
    auto nodeReader = NodeReader::getInstance();
    nodeReader->setPropsWithFlatBuffers(bone, (Table*)options->nodeOptions());

    return bone;
}
