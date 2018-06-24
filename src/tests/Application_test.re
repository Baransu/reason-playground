open Jest;
open Expect;

test("addition", _ =>
  expect(3 + 4) |> toBe(7)
);