# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
from taskgraph.transforms.base import TransformSequence

transforms = TransformSequence()

#: Attributes a fuzz task inherits from the build it runs against.
BUILD_ATTRIBUTES = ("build_platform", "build_type", "fuzz", "tlsfuzz")


@transforms.add
def copy_build_attributes(config, tasks):
    """Give each fuzz task the platform attributes of the build it depends on.

    Without them target_tasks.filter_platform() cannot place the task on a
    platform and drops it, so no fuzz task is selectable with try syntax.
    """
    for task in tasks:
        dep = config.kind_dependencies_tasks[task["dependencies"]["build"]]
        attributes = task.setdefault("attributes", {})
        attributes.update({a: dep.attributes[a] for a in BUILD_ATTRIBUTES})
        yield task
