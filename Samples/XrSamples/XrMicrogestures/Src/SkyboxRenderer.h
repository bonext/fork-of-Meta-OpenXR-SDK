/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * Licensed under the Oculus SDK License Agreement (the "License");
 * you may not use the Oculus SDK except in compliance with the License,
 * which is provided at the time of installation or download, or which
 * otherwise accompanies this software in either electronic or hard copy form.
 *
 * You may obtain a copy of the License at
 * https://developer.oculus.com/licenses/oculussdk/
 *
 * Unless required by applicable law or agreed to in writing, the Oculus SDK
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "Misc/Log.h"
#include "Model/SceneView.h"
#include "Render/GlProgram.h"
#include "Render/SurfaceRender.h"
#include "OVR_FileSys.h"
#include "OVR_Math.h"

#include <memory>
#include <string>
#include <vector>

#if defined(ANDROID)
#define XR_USE_GRAPHICS_API_OPENGL_ES 1
#define XR_USE_PLATFORM_ANDROID 1
#else
#include "unknwn.h"
#define XR_USE_GRAPHICS_API_OPENGL 1
#define XR_USE_PLATFORM_WIN32 1
#endif

#include <openxr/openxr.h>
#include <meta_openxr_preview/openxr_oculus_helpers.h>
#include <openxr/openxr_platform.h>

namespace OVRFW {

class SkyboxRenderer {
   public:
    SkyboxRenderer() = default;

    ~SkyboxRenderer() = default;

    bool Init(std::string modelPath, OVRFW::ovrFileSys* fileSys);

    void Shutdown();

    void Render(std::vector<ovrDrawSurface>& surfaceList);

    bool IsInitialized() const;

   public:
    OVR::Vector3f TopColor;
    OVR::Vector3f MiddleColor;
    OVR::Vector3f BottomColor;
    OVR::Vector3f Direction;

   private:
    bool Initialized = false;
    GlProgram ProgRenderModel;
    ModelFile* RenderModel = nullptr;
    GlTexture RenderModelTextureSolid;
    OVR::Matrix4f Transform;
};

} // namespace OVRFW