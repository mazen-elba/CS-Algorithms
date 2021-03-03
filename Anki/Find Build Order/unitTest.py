%%writefile test_build_order.py
from nose.tools import assert_equal, assert_true

class TestBuildOrder(object):

    def __init__(self):
        self.dependencies = [
            Dependency("d", "g"),
            Dependency("f", "c"),
            Dependency("f", "b"),
            Dependency("f", "a"),
            Dependency("c", "a"),
            Dependency("b", "a"),
            Dependency("a", "e"),
            Dependency("b", "e"),
        ]

    def test_build_order(self):
        build_order = BuildOrder(self.dependencies)
        processed_nodes = build_order.find_build_order()

        expected_result0 = ("d", "f")
        expected_result1 = ("c", "b", "g")

        assert_true(processed_nodes[0].key  in expected_result0)
        assert_true(processed_nodes[1].key  in expected_result0)
        assert_true(processed_nodes[2].key  in expected_result1)
        assert_true(processed_nodes[3].key  in expected_result1)
        assert_true(processed_nodes[4].key  in expected_result1)
        assert_true(processed_nodes[5].key  in "a")
        assert_true(processed_nodes[6].key  in "e")

        print("SUCCESS: test_build_order")

    def test_build_order_circular(self):
        self.dependencies.append(Dependency("e", "f"))
        build_order = BuildOrder(self.dependencies)
        processed_nodes = build_order.find_build_order()
        assert_true(processed_nodes is None)

        print("SUCCESS: test_build_order_circular")

if __name__ == "__main__":
    test = TestBuildOrder()
    test.test_build_order()
    test.test_build_order_circular()